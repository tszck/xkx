// /guanwai/xiaowu.c

inherit ROOM;

void create()
{
	set("short", "小茅屋");
	set("long", @LONG
這是一座用長白山松木壘成的小屋，屋內打掃的很乾淨。四周的牆
壁上掛滿了獸皮和雪橇，一張小小的桌旁坐着一個英俊少年。
LONG );
	set("exits", ([
		"south" : __DIR__"baihe",
	]));
	set("objects", ([
		__DIR__"npc/hufei" : 1,
	]));
	set("no_beg", "1");
	set("no_fight", "1");
	set("coor/x", 6140);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
}
