// Room: /d/chengdu/niangjiuwu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "釀酒屋");
	set("long", @LONG
你來到一座老式的房子中間。在你的左手面有一個很大很大的木桶，
約有二人多高。在木桶的上面，站着幾個精赤着上身的大漢，手裏拿着
竹竿在奮力的朝木桶攪動着。正前方站着一個半老的徐娘，在和幾個小
夥子眉來眼去地説笑着。
LONG	);
	set("exits", ([
		"northwest" : __DIR__"xiaojie2",
	]));
	set("objects", ([
		__DIR__"npc/wangerniang" : 1,
		__DIR__"npc/xiaohuozi" : 3,
	]));
	set("coor/x", -8000);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

