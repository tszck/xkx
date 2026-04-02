// Room: /d/nanshaolin/zhlou4.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鐘樓四層");
	set("long", @LONG
到這裏樓梯大概只能容一人上下，牆身也略薄了些。視線越過窗欞，
北邊的練武場，羅漢堂，般若堂歷歷在目，不少僧人正彙集在練武場上
習武，吆喝聲一陣陣傳進耳鼓。西邊的天王殿，山門殿也盡露全貌。
LONG );
	set("exits", ([
		"up"   : __DIR__"zhlou5",
		"down" : __DIR__"zhlou3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}



