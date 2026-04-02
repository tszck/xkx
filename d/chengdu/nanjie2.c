// Room: /d/chengdu/nanjie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
這裏是成都的南大街，雙人合抱的梧桐在街邊十步一株，青石鋪就
的路面打掃得乾乾淨淨。因爲這裏大都進出的是官府的人，又是王府必
經之路，所以不許閒雜人等無事逗留的。東邊是成都大衙，西邊是個全
城有名的說書場。西北便是名聞天下的青羊宮了。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"      : __DIR__"tidujie",
		"west"      : __DIR__"shuchang",
		"south"     : __DIR__"nanjie",
		"north"     : __DIR__"nanjie1",
		"northwest" : __DIR__"qingyang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

