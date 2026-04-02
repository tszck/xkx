// /kaifeng/longting.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "龍亭大殿");
	set("long", @LONG
龍亭大殿原先是帝王行宮，後宋亡之後，宮殿頹廢，後人在此地復
建大殿，殿內珍寶林陳高檐直柱，令人歎爲觀止。集南北宮殿建築之大
成。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"tingyuan",
	]));

	setup();
	replace_program(ROOM);
}
