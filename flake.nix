{
  description = "NyanSystems tomonidan C da yozilgan kompilyator";

  inputs = {
    # Hozirgi paytdagi nixpkgs stabil reliziga qaratilgan. Agar
    # istasangiz buni biron eskiroq versiyaga qo'yib ishlatishingiz
    # mumkin yoki unstable nostabil reliz ham mavjud judayam yangi
    # narsalar ishlatish niyatida bo'lsangiz.
    #
    # Masalan, agar o'zingizni suetolog his qilsangiz...
    # nixpkgs.url = "github:NixOS/nixpkgs/unstable";
    nixpkgs.url = "github:NixOS/nixpkgs/23.11";

    # Xar hil flake bilan ishlashga utilitalar
    utils.url = "github:numtide/flake-utils";
  };

    outputs = { self, nixpkgs, ... }@inputs: inputs.utils.lib.eachSystem [
    # O'zingiz qo'llab quvvatlash xohlagan arxitekturalar shu yerga qo'shing.
    # Esda tuting: Hamma paketlarniyam stabil va rasmiy nixpkgs har xil
    # arxitekturalarda qo'llab quvvatlamaydi.
    "x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin"
  ] (system: let
    pkgs = import nixpkgs {
      inherit system;

      # Agar nixpkgs dagi biron rasmiy paket o'zgartirish kerak
      # bo'lsa, shu yerga overlay shaklda qo'shing o'zgarishlarni.
      overlays = [];

      # Agar sizga biron tekin bo'lmagan dastur kerak bo'lsa (masalan,
      # cuda), commentdan olib tashlang.
      #
      # config.allowUnfree = true;
    };
  in {
    devShells.default = pkgs.mkShell rec {
      name = "nya";

      packages = with pkgs; [
        # Development Tools
        llvmPackages_14.clang
        cmake
        cmakeCurses

        # Development time dependencies
        gtest

        # Build time and Run time dependencies
        spdlog
        abseil-cpp
      ];

      # Setting up the environment variables you need during
      # development.
      shellHook = let
        icon = "f121";
      in ''
        export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
      '';
    };

    packages.default = pkgs.callPackage ./default.nix {};
  });

}
