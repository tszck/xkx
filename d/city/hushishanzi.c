// Room: /city/hushishanzi.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "湖石山子");
	set("long", @LONG
湖石山子橫亙於院落當中，上與樓連，下與廳接。山上有石蹬盤旋，
山腹有洞彎曲迂迴。更有兩株白皮松植于山半，枝幹虯曲，有凌空欲去
的氣概，石蹬蜿蜒三折，有樓屋五楹，樓南臨水而立。
LONG );
	set("exits", ([
		"west"       : __DIR__"shufengguan",
		"southwest"  : __DIR__"meichuanxuan",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -47);
	set("coor/z", 0);
	set("no_quest",1);
	setup();
	replace_program(ROOM);
}