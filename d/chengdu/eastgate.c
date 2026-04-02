// Room: eastgate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "東城門");
	set("long", @LONG
這是成都東城門，城門正上方刻着“東門”兩個楷書大字，城牆上
貼着幾張官府告示(gaoshi)。一條筆直的青石板大道向東西兩邊延伸。
東邊是郊外，一片平平展展的平原風光，真是不愧天府之國的美稱。西
邊是城裏。
LONG	);
	set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : __DIR__"fuheqiaoe",
		"west"  : __DIR__"dongjie3",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -8010);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n成都提督\n吳天德\n";
}
