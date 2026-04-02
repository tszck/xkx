// Room: /d/chengdu/shimiao.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "昭覺寺");
	set("long", @LONG
昭覺寺素有川西“第一禪林”之稱，始建於唐貞觀年。只見寺內殿
宇宏麗，庭院幽深，古木參天。正殿供奉着我佛如來，大佛兩旁有弟子
菩薩，力士、天王、羅漢等，個個慈眉善目。
LONG	);
	set("exits", ([
		"south" : __DIR__"dongjie2",
		"north" : __DIR__"shimiao2",
	]));
	set("objects", ([
		__DIR__"npc/zhike" : 1,
		__DIR__"npc/xiaoheshang1" : 1,
	]));
	set("coor/x", -8030);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

