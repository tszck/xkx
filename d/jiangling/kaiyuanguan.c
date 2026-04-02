//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "開元觀");
	set ("long", @LONG
這是一座著名的古道觀，遠望山門，隱約可見觀內幾座大殿重檐錯
落，雄渾壯觀。觀內四壁刻有文人墨客的題詞，擺放的鐘、爐、鐵鑊等
等，無不古意盎然。
LONG);
	set("exits", ([ 
                "east"  : __DIR__"xijie4",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}