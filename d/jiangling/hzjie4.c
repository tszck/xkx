//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "漢正街");
	set ("long", @LONG
這是武漢最繁華的街道。從大江南北來的各色人等，熙熙攘攘，摩
肩接踵。東邊是一家客棧，西邊是賣藥材的店鋪，似乎有人在炮製中藥，
傳來一陣陣舂石臼的聲音。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east" : __DIR__"kedian",
		"west" : __DIR__"yaocaidian",
		"south": __DIR__"hzjie5",
		"north": __DIR__"hzjie3",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
