// Room: /d/heimuya/neishi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "小舍內室");
	set("long", @LONG
這裏是小舍內室。收拾得精細異常。你一進去，就發現牀沿坐着一
個打扮妖豔的人。那人也詫異地抬頭，你發現他居然是個男人，手裏執
着一枚繡花針！
LONG    );
	set("exits", ([
		"west" : __DIR__"xiaoshe",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/dongfang": 1,
	]));
	set("coor/x", -3240);
	set("coor/y", 4220);
	set("coor/z", 100);
	setup();
}
