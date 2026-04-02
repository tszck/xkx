inherit ROOM;

void create()
{
        set("short", "牟尼堂");
        set("long",@LONG
這是高僧們的靜修之處。整堂全以松木製成，板門木柱，木料均不去
皮，天然質樸，和一路行來金碧輝煌的殿堂截然不同。室中五個和尚分坐
五個蒲團。四僧朝外，東首一個和尚面朝裏壁一動不動。
LONG
        );
        set("exits", ([
		"north": __DIR__"banruotai",
	]));
	set("objects",([
                __DIR__"npc/benchen" : 1,
		__DIR__"npc/kurong" : 1,
		__DIR__"npc/benguan" : 1,
		__DIR__"npc/benxiang" : 1,
		__DIR__"npc/bencan" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -57100);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
