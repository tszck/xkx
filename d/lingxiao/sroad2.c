// Room: /d/lingxiao/sroad2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
這時雪更大些了，使得地上蓋上了厚厚的一層。正值朝陽初出，從
山頂倒掛下來的冰川，由於太陽光的折射和發射，整個冰層都變成淺藍
色的透明體，那些末曾凝結的雪花，在陽光底下，泛出霞輝麗彩，奇妙
得難以形容。山路也漸漸不平坦起來，走一步跌三步，聯想到古詩所說
：“去時雪滿天山路”，也不過如此吧。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
	    "southdown" : __DIR__"sroad1",
	    "northup"   : __DIR__"sroad3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8990);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}

