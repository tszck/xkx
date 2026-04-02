// Room: /d/tiezhang/zzfeng.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "中指峯");
	set("long", @LONG
這裏就是鐵掌山的最高峯——中指峯。由於山勢太高，峯頂仍存有
大量的積雪，白雪皚皚，在陽光的照射下，泛起一片耀眼的銀光。縱目
遠眺，湘西幾百裏景色盡收眼底，瀘溪，辰溪如兩條玉帶，從山下緩緩
流過。遠處那條白色的亮線，就是湘西的大江——沅江。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"southdown" : __DIR__"shanlu9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1770);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
