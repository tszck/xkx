// Room: /yangzhou/meichuanxuan.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "梅船軒");
	set("long", @LONG
中央有廳三楹，南向明間廊柱上，懸一幅楹聯(lian)。在廳的四周
地坪上，以鵝卵石與瓦片鋪地，紋作“水波粼粼”狀。給人一水的意境。
廳的四壁，皆是明窗，人在其中，可以作四面觀。廳的東南，有老槐蔭
蔽，山石少許，點綴其間。廳的東北，以湖石貼牆作山，山勢時起時伏，
逶迤而西。有石蹬可登。
LONG );
	set("outdoors", "yangzhouw");

	set("no_fight", 1);
	set("exits", ([
		"south"     : __DIR__"chuanlang",
		"northeast" : __DIR__"hushishanzi",
	]));
	set("objects", ([
		__DIR__"npc/yangwanxiao" : 1,
	]));
	set("item_desc", ([
		"lian" : @LONG
                  花         約
                  爲         作
                  四         主
                  壁         人
                  船         梅
                  爲         作
                  家         客
LONG,
	]));
	set("coor/x", -11);
	set("coor/y", -48);
	set("coor/z", 0);
	set("no_quest",1);
	setup();
	replace_program(ROOM);
}