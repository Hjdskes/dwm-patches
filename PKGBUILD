pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
groups=(custom)
license=('MIT')
depends=('libx11')
options=(zipman)
provides=('dwm')
conflicts=('dwm-pango')
_source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
        config.h)
_patches=(
		  00-dwm-6.0-pertag2.diff
		  01-dwm-6.0-statuscolors.diff
		  02-dwm-6.0-hideempty.diff
		  03-dwm-6.0-chat.diff
		  04-dwm-6.0-push.diff
		  05-dwm-6.0-cycle.diff
		  06-dwm-6.0-occupiedcol.diff
		  07-dwm-6.0-singularborders.diff
		  08-dwm-6.0-attachaside.diff
		  09-dwm-6.0-centerclock.diff
		  10-dwm-6.0-monocleindicator.diff
		  11-dwm-6.0-focusfollowmousetag.diff
		  12-dwm-6.0-removeunfunc.diff
		  13-dwm-6.0-xkeycodetokeysymfix.diff
		  14-dwm-6.0-deck.diff
		  15-dwm-6.0-smfact.diff
		 )
source=(${_source[@]} ${_patches[@]})

build() {
	cd $srcdir/$pkgname-$pkgver
	cp $srcdir/config.h config.h

	for PATCH in "${_patches[@]}"; do
		msg "${PATCH##*/}" && patch -Np1 dwm.c "${startdir}/${PATCH##*/}"
	done

	make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
	make PREFIX=/usr DESTDIR=$pkgdir install

	install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
}
