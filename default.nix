{ lib
, llvmPackages
, cmake
, curl
, jansson }:

llvmPackages.stdenv.mkDerivation rec {
  pname = "nya";
  version = "0.1.0";

  src = ./.;

  nativeBuildInputs = [ cmake ];
  buildInputs = [ curl jansson ];

  cmakeFlags = [
    "-DENABLE_TESTING=OFF"
    "-DENABLE_INSTALL=ON"
  ];

  meta = with lib; {
    homepage = "https://github.com/NyanSystems/nya";
    description = ''
      NyanSystems tomonidan C da  yozilgan kompilyator.";
    '';
    licencse = licenses.mit;
    platforms = with platforms; linux ++ darwin;

    # Bu yerga faqat "Silent Carnage LTC" dasturchilar qo'shilishi mumkin
    maintainers = [
      {
        name = "Sokhibjon Orzikulov";
        email = "sakhib@orzklv.uz";
        handle = "orzklv";
        github = "orzklv";
        githubId = 54666588;
        keys = [{
          fingerprint = "00D2 7BC6 8707 0683 FBB9  137C 3C35 D3AF 0DA1 D6A8";
        }];
      }
      {
        name = "thelissimus";
        email = "thelissimus@tuta.io";
        handle = "thelissimus";
        github = "thelissimus";
        githubId = 70096720;
        keys = [{
          fingerprint = "6CF0 B081 B4C5 7414 BD7A  09D5 464C A2FF 1D27 D92C";
        }];
      }
    ];
  };
}
