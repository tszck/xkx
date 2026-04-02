// Room: /d/heimuya/baistep2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","長廊");
	set("long", @LONG
這裏是白虎堂的長廊。兩邊一片狼藉，看樣子剛被洗劫一場，遍地
橫屍，慘不忍賭。
LONG );
	set("outdoors", "heimuya");
	set("exits",([
		"north" : __DIR__"baistep1",
		"south" : __DIR__"baihutang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
