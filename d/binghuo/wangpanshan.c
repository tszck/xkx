// Room: /binghuo/wangpanshan.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "王盤山海灘");
	set("long", @LONG
只聽得島上號角之聲嗚嗚吹起，岸邊兩人各舉大旗，揮舞示意。
只見兩面大旗上均繡着一頭大鷹，雙翅伸展，甚是威武。兩面大旗之
間站着一個老者。只聽他朗聲說道：“玄武壇白龜壽恭迎貴客。”聲
音漫長，綿綿密密，雖不響亮，卻是氣韻醇厚。往南是一個山谷。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("exits", ([
		"south" : __DIR__"wangpangu1",
		"east"  : __DIR__"wangpanlin",
	]));
	set("objects", ([
		"/d/mingjiao/npc/baiguishou" : 1,
	]));
	setup();
	replace_program(ROOM);
}

