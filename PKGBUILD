pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
depends=('libxinerama' 'pango')
options=(zipman)
provides=('dwm')
conflicts=('dwm-pango')
_source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
        config.h)
_patches=(01-dwm-6.0-xft.diff
          02-dwm-6.0-pertag2.diff
          03-dwm-6.0-uselessgaps.diff
          04-dwm-6.0-systray.diff
		  05-dwm-6.0-urgentcolor.diff
		  06-dwm-6.0-occupiedcol.diff
          07-dwm-6.0-monocle_fixes.diff
	 	  08-dwm-6.0-statusallmons.diff
          09-dwm-6.0-chat.diff
          10-dwm-6.0-no_title.diff
          11-dwm-6.0-XKeycodeToKeysym_fix.diff
          00-dwm-6.0-buildflags.diff)
source=(${_source[@]} ${_patches[@]})

build() {
  for PATCH in "${_patches[@]}"; do
    msg "${PATCH##*/}" && patch -Np1 -i "${startdir}/${PATCH##*/}"
  done

  cd $srcdir/$pkgname-$pkgver
  cp $srcdir/config.h config.h

  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11 || return 1
  make PREFIX=/usr DESTDIR=$pkgdir install || return 1

  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE && \
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
}
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '4ef70d706595483d87b802b58fd0db62'
         'b05a6e87e97f2d6ce29615dc1675fd6a'
         '0eb41bf700c80fe53c4c664b4da164fc'
         'a98f282724e43df243e2bcfc0d38036e'
         '4c79e30086e40d4904785b816ac73241'
         '728ea190ee783e8b4f77c0e51eeaf822'
         'f8c7ef84b1322ac0911ad8386f51d58c'
         '5f0b7065e44b3aec0d5393c9833b7d0f'
         'aa1b23aca5b1339a88fc4a3a17dbed3f'
         'bf47c515c7dcd31923872ad42af3224a'
         '045b5455cdcb5a226e6baf921d913751'
         '715c20080e88580138cb0acf29f6362d'
         '27175d10e252cb39a40b331c4ba3b2ce')
