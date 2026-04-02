// Room: /d/nanshaolin/qxdian.c 清心殿
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"清心殿"NOR);
	set("long",@long
這裏是一座空曠的大佛殿，裏面供奉着幾尊佛像，殿中擺放着幾個
蒲團，殿的四周各裝嵌着一排雕花木製長窗，陽光透過窗欞灑進大殿，
照的大殿一片金光。陣陣梵唱傳來使你覺得清新寡慾，俗念全消。
long);
	set("exits",([
		"west" : __DIR__"dabeidian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


