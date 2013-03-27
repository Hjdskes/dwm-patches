This is my personal DWM
=========

**In this repository you will find my patches, my config.h and the Arch Linux PKGBUILD.**

The `Other patches` directory contains, well, other patches. They're just a collection of patches I saved up over time; most of them I used in previous setups. They're all diffed against a vanilla dwm.c, so if you want to combine some you will probably have to hand patch a bit.

**ToDo:**
* Try adapt the way multimonitor is treated: make it like GNOME Shell - basically make the extra monitor one single tag on its own
* Implement runorraise? First find out if this can be done on a more global level too, e.g. dmenu.

**Issues:**
* singular borders
	* on multimonitor, you see monitor one's borders on monitor two and vice-versa.
	* in gridlayout, we can't hide either the left or the right screen edge's border off-screen.
* smfact
	* with more than 30 clients, increasing smfact too much will crash DWM.
	* negative smfact can't properly function the way it is, so for now remains disabled.
* netwmdemandsattention
	* having the window manager set hints for a client is directly contrary to ICCCM §4.1.2. We could just use `c->isurgent = True`, but that does not give us the actual urgent border. Seeing DWM does mess with hints (in `clearurgent()` and in `updatewmhints()`, I'm not making it that big of an issue.
