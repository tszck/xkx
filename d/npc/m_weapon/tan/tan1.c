//tan1.c

inherit ROOM;

void create()
{
	set("short", "嘉興南湖 ");
	set("long",
	     "這裏是嘉興南湖水下 ，四周倒還比較明亮，幾道天光從頭頂的潭水中投射下來，\n"
	     "顯得十分美麗。腳下漆黑一片也不知有些什麼。你不由對自己説......\n"

	);
	set("exits", ([
		"up"   : "/d/jiaxing/nanhu1",
		"down" : __DIR__"tan2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -1010);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
