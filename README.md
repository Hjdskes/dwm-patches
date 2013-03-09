This is my personal DWM
=========

**In this repository you will find my patches, my config.h and the Arch Linux PKGBUILD.**

The `Other patches` directory contains, well, other patches. They're just a collection of patches I saved up over time; most of them I used in previous setups. Some are diff'ed against a vanilla dwm.c, but others are not so they will require hand-patching.

The `Under construction` directory contains files I'm still working on, but not currently using. **It might not be in a usable state!**

ToDO:
* Spacing of layout symbol in the actual code --> XFT patch.
* Don't make the text transparent with a transparent statusbar.
	* Move unsigned long real_opacity[] someplace else, use only once. 
* Implement runorraise? First find out if this can be done on a more global level too, e.g. dmenu.
* Try cleaning up patches and code.
