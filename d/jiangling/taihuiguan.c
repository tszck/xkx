//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "太暉觀");
	set ("long", @LONG
這裏原是明太祖朱元璋第十二子朱柏的王宮。飛樓湧殿，雄甲荊楚，
人稱賽武當。在高高的平臺上是一座約十米見方的金殿，頂覆銅瓦，驕
陽映照之下，閃光奪目，數裏之外，均能看見。
LONG);

	set("exits", ([ 
      "east" : __DIR__"xiaowu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2055);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
