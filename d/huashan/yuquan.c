// yuquan.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "玉泉院");
	set("long", @LONG
這裏因屋後的玉泉而得名，是宋代陳希夷隱居的地方。周圍生着十
二株大龍藤，夭矯多姿，枝幹中空，就如飛龍相似，相傳是希夷先生陳
摶老祖所植。院內綠廕庇日，泉石如畫，流水縈迴，迴廊曲折。院中有
清泉一股，泉水甘冽，傳與山頂鎮嶽宮玉井相通，故名玉泉，玉泉院因
此得名。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"path1",
	]));
	set("objects", ([
		__DIR__"npc/teller": 1
	]) );
	set("outdoors", "huashan");

	set("coor/x", -920);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
 
