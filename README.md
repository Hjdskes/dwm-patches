This is my personal DWM
=========

**In this repository you will find my patches, my config.h and the Arch Linux PKGBUILD.**

The `Other patches` directory contains, well, other patches. They're just a collection of patches I saved up over time; most of them I used in previous setups. Some are diff'ed against a vanilla dwm.c, but others are not so they will require hand-patching.

**ToDo:**
* Fix chatlayout again with singularborders when buddy list isnt shown
* Try adapt the way multimonitor is treated: make it like GNOME Shell - basically make monitor2 one, single tag on its own
* Spacing of layout symbol in the actual code --> XFT patch.
* Move unsigned long real_opacity[] someplace else, use only once --> transparent statusbar patch. 
* Implement runorraise? First find out if this can be done on a more global level too, e.g. dmenu.
* Try cleaning up patches and code.

**Issues:**
* singular borders
	* on multimonitor, you see monitor one's borders on monitor two and vice-versa
	* floating clients will hide behind tiled clients when changed focus
