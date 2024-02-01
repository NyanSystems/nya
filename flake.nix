{
  description = "NyanSystems tomonidan C da yozilgan kompilyator";

  inputs = {
    # Hozirgi paytdagi nixpkgs stabil reliziga qaratilgan. Agar
    # istasangiz buni biron eskiroq versiyaga qo'yib ishlatishingiz
    # mumkin yoki unstable nostabil reliz ham mavjud judayam yangi
    # narsalar ishlatish niyatida bo'lsangiz.
    #
    # Masalan, agar o'zingizni suetolog his qilsangiz...
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    # Agar mental sog' bo'lsangiz...
    # nixpkgs.url = "github:NixOS/nixpkgs/23.11";

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
        wget # Fayllarni tarmoqdan yuklash uchun
        unzip # Fayllarni arxivdan chiqarish uchun
      ];

      # Terminaldagi muhitni ishlash uchun kerakli qismlar sozlash.
      shellHook = let
        icon = "(* ^ ω ^)";
      in ''
        export PS1="\[$(tput setaf 1)\]$(echo -e '${icon}')\[$(tput setaf 2)\] {\[$(tput setaf 3)\]\w\[$(tput setaf 2)\]} \[$(tput setaf 5)\](${name})\[$(tput setaf 6)\] \\$ -> \[$(tput sgr0)\]"

        # Let's make some announcements
        figlet -f slant ${name} | lolcat
        printf "\n"
        printf "Welcome to ${name}'s compiler development environment!\n" | lolcat
        printf "\n"

        # Check if there's "helpers" folder in the current directory, if no - create it
        if [ ! -d helpers ]; then
          printf "Creating helpers folder...\n" | lolcat
          mkdir helpers

          printf "Downloading lib${name}...\n" | lolcat
          wget https://github.com/NyanSystems/libnya/archive/refs/heads/main.zip

          printf "Unzipping libnya...\n" | lolcat
          unzip main.zip

          printf "Moving libnya...\n" | lolcat
          rm main.zip
          mv libnya-main/src/* helpers
          mv libnya-main/include/* helpers
          rm -rf libnya-main
        fi

        # Check if there's "build" folder in the current directory, if no - create it
        if [ ! -d build ]; then
          printf "Creating build folder...\n" | lolcat
          mkdir -p build/helpers

          printf "Building lib${name}...\n" | lolcat
          cd build
          cmake ..
          cmake --build .
          cd ..
        fi

        _cleanup()
        {
            printf "\nTime to say goodbye, Nya!\n" | lolcat
            printf "I'll cleanup some garbage for you...\n" | lolcat
            rm -rf helpers
            rm -rf build
        }

        trap _cleanup EXIT
      '';
    };

    packages.default = pkgs.callPackage ./default.nix {};
  });

}
