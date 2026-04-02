// Room: /d/nanshaolin/jietan2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "戒壇");
	set("long", @LONG
這是一個正方形，四角攢尖頂的亭臺式建築。是寺中僧徒受戒的地
方。壇上正中放有佛身相連，向背而坐的雙面銅鑄佛像，面北的是藥師
佛，面南的為阿彌陀佛。壇上空無一人，寂靜無聲，越發顯得此處的莊
嚴肅穆。
LONG );
	set("exits", ([
		"west"      : __DIR__"jietan1",
		"north"     : __DIR__"jietan4",
		"southwest" : __DIR__"sblu-3",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1830);
	set("coor/y", -6130);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

