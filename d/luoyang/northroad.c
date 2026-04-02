//  Room:  /d/luoyang/northroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "中州街");
	set("long",  @LONG
不知道為什麼，走在這條路上，總感覺差了點什麼，也許由於連年
的戰亂，使得本來很熱鬧的街市冷冷清清，道路兩旁的店鋪早已破舊不
堪，一眼望去便知道有很久沒有人居住了。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"  :  __DIR__"northgate",
		"south"  :  __DIR__"center",
	]));
	set("objects",  ([
		"/d/huashan/npc/youke" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
