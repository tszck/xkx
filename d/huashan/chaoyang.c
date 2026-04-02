// chaoyang.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "朝陽峯");
	set("long", @LONG
這裏就是華山的東峯，也稱朝陽峯，是華山看日出的絕佳處。於此
俯瞰，黃河隱顯東迤如帶，南望小孤峯背倚山河。小孤峯上有一小亭，
覆以鐵瓦，亭中有鐵棋盤一局，那就是華山著名的“博臺”了。東壁懸
崖上，更有一個巨型掌印，相傳爲「河神巨靈」劈山時所留下的，李白
詩中“巨靈咆哮劈兩山，洪波噴流射東海”就是指這個上古傳說。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"westdown" : __DIR__"chaopath2",
	]));
	set("objects", ([
		CLASS_D("huashan")+"/gao-laozhe": 1,
		CLASS_D("huashan")+"/ai-laozhe": 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -850);
	set("coor/y", 220);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}
 
