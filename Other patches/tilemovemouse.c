#define INRECT(X,Y,RX,RY,RW,RH) ((X) >= (RX) && (X) < (RX) + (RW) && (Y) >= (RY) && (Y) < (RY) + (RH))

void
insertbefore(Client *a, Client *b) { /* insert a before b in the client list */
	Monitor *m = a->mon;
	Client **x = &m->clients;

	while(*x != b && *x)
		x = & (*x)->next;
	*x = a;
	a->next = b;
}

void
insertafter(Client *a, Client *b) { /* insert a after b in the client list */
	a->next = b->next;
	b->next = a;
}

void
tilemovemouse(const Arg *arg) {
	/* Could EnterNotify events be used instead? */
	Client *c, *d;
	Monitor *m;
	XEvent ev;
	int x, y;
	Bool after;

	if(!(c = selmon->sel))
		return;

	if((m = recttomon(c->x, c->y, c->w, c->h)) != selmon) {
		sendmon(c, m);
		selmon = m;
		focus(NULL);
	}

	if(c->isfloating || !selmon->lt[selmon->sellt]->arrange){
		movemouse(NULL);
		return;
	}
	if(XGrabPointer(dpy, root, False, MOUSEMASK, GrabModeAsync, GrabModeAsync,
		None, cursor[CurMove], CurrentTime) != GrabSuccess)
		return;
	do {
		XMaskEvent(dpy, MOUSEMASK|ExposureMask|SubstructureRedirectMask, &ev);
		switch (ev.type) {
		case ConfigureRequest:
		case Expose:
		case MapRequest:
			handler[ev.type](&ev);
			break;
		case MotionNotify:
			x = ev.xmotion.x;
			y = ev.xmotion.y;
			after = False;
			for(d = nexttiled(m->clients); d; d = nexttiled(d->next)){
				if(d == c)
					after = True;
				else if(INRECT(x, y, d->x, d->y, d->w+2*borderpx, d->h+2*borderpx)){
					detach(c);
					after ? insertafter(c, d) : insertbefore(c,d);
					arrange(c->mon);
					break;
				}
			}
		}
	} while(ev.type != ButtonRelease);
	XUngrabPointer(dpy, CurrentTime);
}
