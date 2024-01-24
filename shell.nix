let
  # Fetch the nixpkgs-unstable channel
  nixpkgs = builtins.fetchTarball {
    url = "https://github.com/NixOS/nixpkgs/archive/nixpkgs-unstable.tar.gz";
  };
  libnya.url = "github:NyanSystems/libnya";
  pkgs = import nixpkgs {
      # Agar nixpkgs dagi biron rasmiy paket o'zgartirish kerak
      # bo'lsa, shu yerga overlay shaklda qo'shing o'zgarishlarni.
      overlays = [
        (self: super: {
          # Add libnya as a package
          nyan = super.callPackage libnya { };
        })
      ];

      # Agar sizga biron tekin bo'lmagan dastur kerak bo'lsa (masalan,
      # cuda), commentdan olib tashlang.
      #
      # config.allowUnfree = true;
  };
in
pkgs.mkShell rec {
  name = "nya";

  packages = with pkgs; [
    # Asbob-uskunalar
    ## LLVM utilitalari
    lldb
    cmake
    clang-tools
    cmakeCurses
    llvmPackages.llvm
    llvmPackages.clang
    ## GNU utilitalari
    gcc
    # gdb
    gnumake
    # valgrind
    
    # Ustida ishlayotgandagi ishlatilgan kutubxonalar

    # Build va rantaym paytgi kutubxonalar
    curl  # Tarmoq bilan ishlash uchun
    jansson  # JSON bilan ishlash uchun
    nyan  # Nyan bilan ishlash uchun
  ];

  # Terminaldagi muhitni ishlash uchun kerakli qismlar sozlash.
  shellHook = let
    icon = "f121";
  in ''
    export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
  '';
}