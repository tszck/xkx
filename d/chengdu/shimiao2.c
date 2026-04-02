// Room: /d/chengdu/shimiao2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "大雄寶殿");
	set("long", @LONG
這裏雄偉莊嚴的大雄寶殿，兩邊是青面撩牙的四大金剛，中間供奉
着如來佛祖的金像，殿內香煙繚繞，無數善男信女來此燒香磕頭，正中
是一塊蒲團，供香客禮拜。右手是善緣箱，供錢財佈施用。
LONG	);
	set("exits", ([
		"south" : __DIR__"shimiao",
	]));
	set("objects", ([
		__DIR__"npc/yuanseng" : 1,
		__DIR__"obj/box1" : 1,
	]));
	set("coor/x", -8030);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

