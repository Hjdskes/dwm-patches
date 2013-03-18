pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
groups=(custom)
license=('MIT')
depends=('libxinerama' 'libxft')
options=(zipman)
provides=('dwm')
conflicts=('dwm-pango')
_source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
        config.h
		push.c)
_patches=(00-dwm-6.0-pertag2.diff
		  01-dwm-6.0-statuscolors.diff
		  02-dwm-6.0-hideempty.diff
		  03-dwm-6.0-chat.diff
		  04-dwm-6.0-occupiedcol.diff
		  05-dwm-6.0-singularborders.diff
#		  05-dwm-6.0-singularborders2.diff
		  06-dwm-6.0-attachaside.diff
		  07-dwm-6.0-centerclock.diff
#		  08-dwm-6.0-monoclefixes.diff
		  09-dwm-6.0-focusfollowmousetag.diff
		  10-dwm-6.0-removeunfunc.diff
		  11-dwm-6.0-xkeycodetokeysymfix.diff
		 )
source=(${_source[@]} ${_patches[@]})

build() {
  for PATCH in "${_patches[@]}"; do
    msg "${PATCH##*/}" && patch -Np1 -i "${startdir}/${PATCH##*/}"
  done

  cd $srcdir/$pkgname-$pkgver
  cp $srcdir/config.h config.h
  cp $srcdir/push.c push.c

  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11 || return 1
  make PREFIX=/usr DESTDIR=$pkgdir install || return 1

  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE && \
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
}
