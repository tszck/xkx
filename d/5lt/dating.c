// Room: /d/5lt/dating.c

inherit ROOM;

void create()
{
	set("short", "大廳");
	set("long", @LONG
這裏是無釐頭電視臺的大廳。大廳面積很大，足有三個籃球場那麼
大，地板是光滑的大理石，可以玩單排。門口坐着一個保安阿達，他負
責保護電視臺的安全以及一些基本的迎賓工作。大廳上方有個金匾，上
面寫着 5LTTV幾個大字，顯得格外的醒目。東邊有一個小門，通向電視
臺的新聞發佈中心。
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"up"     : __DIR__"mishuchu",
		"out"    : __DIR__"mubanlu",
		"east"   : __DIR__"fbzhongxin",
	]));
        set("objects", ([
		__DIR__"npc/ahda": 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -185);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
