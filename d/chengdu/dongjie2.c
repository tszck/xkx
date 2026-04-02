// Room: /d/chengdu/dongjie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "東大街");
	set("long", @LONG
你剛走到這，就聽到北邊隱隱傳來鐘聲，其中似乎還滲雜着“咚咚”
的木魚之聲。你順着響聲望去，但見眼前一座老高的寺門，門匾上三個
金光大字“昭覺寺”。你往南邊看去，只見到一條小街。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"west"  : __DIR__"dongjie1",
		"east"  : __DIR__"dongjie3",
		"north" : __DIR__"shimiao",
		"south" : __DIR__"xiaojie",
	]));
	set("objects", ([
		__DIR__"npc/seng-ren" : 1,
	]));
	set("coor/x", -8030);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

