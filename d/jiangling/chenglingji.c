//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "城陵磯");
	set ("long", @LONG
這裏是洞庭湖與長江匯合處，水天浩淼，茫茫蕩蕩。幾隻鷗鳥拍打
着翅膀不時從水面橫掠而過。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west" : __DIR__"dangyangqiao",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
