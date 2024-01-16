<p align="center">
    <img src="https://raw.githubusercontent.com/NyanSystems/.github/main/pictures/nya/header.gif?sanitize=true"/>
</p>

<h2 align="center">Nya</h2>

<div align="center">
    <a href="https://github.com/orgs/NyanSystems/repositories">
        <img src="https://img.shields.io/static/v1.svg?style=rounded-square&label=Type&message=Language&logo=4chan&logoColor=311ac5&colorA=ead186&colorB=fe77ff"/>
    </a> 
    <a href="https://github.com/NyanSystems/nya/blob/main/flake.nix">
        <img src="https://img.shields.io/static/v1.svg?style=rounded-square&label=Target&message=*NIX&logo=nixos&logoColor=311ac5&colorA=ead186&colorB=fe77ff"/>
    </a>
</div>

<p align="center">Hamma narsani yozish uchun til va kompilyator.</p>


Nya bu butun [Nyan Systems Inc.] tomonidan yoziladigan dastur va komponentlarni yozish va qo'llab quvvatlash uchun ishlatiladigan [C dasturlash tili](https://en.wikipedia.org/wiki/C_(programming_language)) ustiga qurilgan dasturlash tilidir.

## Boshlash

### O'rnatish

Hozirgi holatda bizda Nix paket menejeridan boshqa paket menejerlarini qo'llab quvvatlay ololmaymiz. Ammo yaqin kelajakda agar dasturlash tilimiz yanada to'liqroq shakli chiqsa, boshqa paket menejerlariga taqdim etishni ham o'ylab ko'ramiz. Ungacha xohlasangiz [biz kompilyatsiya qilgan relizlardan](https://github.com/NyanSystems/nya/releases/) yuklashingiz mumkin.

Yoki hozircha keling Nix paket menejeri orqali ishlatib turamiz:

```shell
# Nix o'rnatilgan va nix-commands yoqilgan
nix run github:NyanSystems/nya
```

### Ishlash

Loyiha a'zolari tomonidan iloji boricha Nix paket menejeri qo'llaniladi va ushbu metodika tavsiya qilinadi, loyihada dasturchi muhitini yaratish uchun nixdagi dev env ishlatiladi. Istalgan 2 muhitlardan birini foydalanish mumkin:

```shell
# shell.nix ishlatadi
nix-shell

# flake.nix dan tortib oladi
nix develop -c "$SHELL"
```

Agar siz nix ishlatish xohishingiz bo'lmasa, nix paket menejeridagi CMake, Clang va GNU Kompilyatorlar versiyasi bilan bir xil yoki yaqin utilitalar qo'yib olish ishlatishingizni tavsiya qilamiz. Ko'proq ma'lumotlarni [flake.nix](https://github.com/NyanSystems/nya/blob/main/flake.nix) va [nix registridan](https://search.nixos.org/packages) topishigniz mumkin.


### Hissa qo'shish

Hozirgi vaqtda loyiha asosiy 3 LTC dasturchilari tomonidan yozib boriladi va qo'llab quvvatlanadi. Yaqin orada ochiq jamiyat tarzda rivojlanuvchi sikl ga o'tish maqsad qilingan. Ungacha taklif va e'tirozlarni [Issue](https://github.com/NyanSystems/nya/issues/new) yoki [PR](https://github.com/NyanSystems/nya/compare) ko'rinishida tashashingiz mumkin. 

<p align="center"><img src="https://raw.githubusercontent.com/NyanSystems/.github/main/pictures/etc/footer.svg?sanitize=true" /></p>

<p align="center">Copyright &copy; 2024-present Nyan Systems Developers</p>

<p align="center"><a href="https://github.com/NyanSystems/nya/blob/main/LICENSE"><img src="https://img.shields.io/badge/License-MIT-fe77ff.svg"/></a></p>

[Nyan Systems Inc.]: https://github.com/NyanSystems