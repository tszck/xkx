// Room: /d/shaolin/gulou4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "鼓樓四層");
	set("long", @LONG
到這裏樓梯大概只能容一人上下，牆身也略薄了些。視線
越過窗欞，南邊的練武場，羅漢堂，般若堂歷歷在目，不少僧
人正彙集在練武場上習武，吆喝聲一陣陣傳進耳鼓。北邊的藏
經樓，方丈樓也盡露全貌。
LONG );
	set("exits", ([
		"up" : __DIR__"gulou5",
		"down" : __DIR__"gulou3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 830);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}