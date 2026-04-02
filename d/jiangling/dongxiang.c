//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "東廂房");
	set ("long", @LONG
這是知府大人和家眷起居的處所。左首一張雕花大木牀，牀上堆疊
着錦被和繡花枕頭。北邊是一條走廊，西邊是一個花圃，隱約傳來陣陣
花的迷香。
LONG);
	set("exits", ([
		"north" : __DIR__"zoulang",
		"west"  : __DIR__"huapu",
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("sleep_room", 1); 
	set("coor/x", -1480);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}