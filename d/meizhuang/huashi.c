// d/meizhuang/huashi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "畫室");
	set("long", @LONG
這裏是丹青生的畫室，俗話說：書畫不分家，所以丹青生的書法也
有相當的功力，雖然不及他三哥禿筆翁很多，但他將他的劍法融於他的
書法當中，也可謂是銀鉤鐵劃了。這裏的陳設和書室差不多，唯一不同
的是這裏的牆上並沒有掛丹青生的丹青妙筆，而是掛了許多前朝名家的
名畫，屬於丹青生自己的是一幅寫着《兵車行》的中堂。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		CLASS_D("heimuya")+"/sheng.c" : 1,
	]));

	set("coor/x", 3510);
	set("coor/y", -1380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
