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
        config.h
		buildflags.diff)
_patches=(
		  00-dwm-6.0-pertag2.diff
		  01-dwm-6.0-xft.diff
		  02-dwm-6.0-statuscolors.diff
		  03-dwm-6.0-hideempty.diff
		  04-dwm-6.0-chat.diff
		  05-dwm-6.0-push.diff
		  06-dwm-6.0-cycle.diff
		  07-dwm-6.0-occupiedcol.diff
		  08-dwm-6.0-singularborders.diff
		  09-dwm-6.0-attachaside.diff
		  10-dwm-6.0-centerclock.diff
		  11-dwm-6.0-monocleindicator.diff
		  12-dwm-6.0-focusfollowmousetag.diff
		  13-dwm-6.0-removeunfunc.diff
		  14-dwm-6.0-xkeycodetokeysymfix.diff
		  15-dwm-6.0-smfact.diff
		  16-dwm-6.0-netwmdemandsattention.diff
		  17-dwm-6.0-closesymbol.diff
		 )
source=(${_source[@]} ${_patches[@]})

build() {
	cd $srcdir/$pkgname-$pkgver
	cp $srcdir/config.h config.h

	patch -Np1 config.mk $srcdir/buildflags.diff
	for PATCH in "${_patches[@]}"; do
		msg "${PATCH##*/}" && patch -Np1 dwm.c "$srcdir/${PATCH##*/}"
	done

	make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
	cd $srcdir/$pkgname-$pkgver 

	make PREFIX=/usr DESTDIR=$pkgdir install
	install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
}
