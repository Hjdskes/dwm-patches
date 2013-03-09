static Client *
prevtiled(Client *c) {
	Client *p, *r;

	for(p = selmon->clients, r = NULL; p && p != c; p = p->next)
		if(!p->isfloating && ISVISIBLE(p))
			r = p;
	return r;
}

static void
pushup(const Arg *arg) {
	Client *sel = selmon->sel;
	Client *c;

	if(!sel || sel->isfloating)
		return;
	if((c = prevtiled(sel))) {
		/* attach before c */
		detach(sel);
		sel->next = c;
		if(selmon->clients == c) {
			selmon->clients = sel;
		} else {
			for(c = selmon->clients; c->next != selmon->sel && c->next != sel->next; c = c->next);
			c->next = sel;
		}
	}
	focus(sel);
	arrange(selmon);
}

static void
pushdown(const Arg *arg) {
	Client *sel = selmon->sel;
	Client *c;

	if(!sel || sel->isfloating)
		return;
	if((c = nexttiled(sel->next))) {
		/* attach after c */
		detach(sel);
		sel->next = c->next;
		c->next = sel;
	}
	focus(sel);
	arrange(selmon);
}
