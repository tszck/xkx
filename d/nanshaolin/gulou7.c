// Room: /d/nanshaolin/gulou7.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鼓樓七層");
	set("long", @LONG
這裏就是鼓樓之頂。直入眼簾的便是一隻大鼓。大鼓鼓身通紅，似
由白楊木箍成。兩頭包以水牛皮，用一匝大銅釘釘在鼓身邊緣。鼓心有
一圈白漬，看來是因爲多次擊打形成的。整個大鼓放在一個一人高的架
子上，架子底層擱着兩根大鼓槌。
LONG );
	set("exits", ([
		"down" : __DIR__"gulou6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
