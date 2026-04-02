//Room: sanbuguan.c
//Date: Feb.12 1998 By Java

inherit ROOM;

void create()
{
	set("short", "三不管");
	set("long", @LONG
這裏是四川、湖北與陝西的交界，俗稱三不管。小土路的兩旁有疏
疏落落的農舍耕田，幾隻牛羊正在喫草。路上行人很少，都匆匆趕路。
LONG);
	set("outdoors", "sanbuguan");
	set("exits", ([
            "east"      : __DIR__"wdroad8",
            "southeast" : __DIR__"wdroad9",
            "southwest" : "/d/emei/wdroad",
	]));
	set("objects", ([
		__DIR__"npc/cow": 1,
	]));
	set("coor/x", -3300);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
