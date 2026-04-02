// Room: /d/nanshaolin/chufang2
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "廚房");
	set("long", @LONG
炊煙繚繞，蒸汽騰騰，香味撲鼻而來。靠牆是一排數丈長的竈臺，
支着十來口大鍋，最大的一口飯鍋上方竟有人從樑上懸空而下，手持木
棍在攪拌。除了燒飯的僧人外，幾位火工頭陀忙着劈柴運薪，竈下爐火
熊熊。一位中年僧人正來回催促着。
LONG );
	set("exits", ([
                "west"  : __DIR__"fanting3",
		"north" : __DIR__"chufang1",
                "south" : __DIR__"xiaolu-1",
	]));
	set("objects",([
		__DIR__"npc/shaofan-seng" : 1,
                __DIR__"npc/hg-toutuo" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

