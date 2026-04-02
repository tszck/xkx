//miaorenbuluo.c

inherit ROOM;

void create()
{
	set("short", "苗人部落");
	set("long", @TEXT
你眼前突然一亮，原來是走進了一個苗人部落。苗人們圍坐在火堆
邊，面色虔誠，好象在作某種祭神儀式。幾個巫士揮舞着木鏜，口中念
念有詞。突然，他們好象發現了你。
TEXT );
	set("outdoors", "mingjiao");
 	set("exits",([
		"north" : __DIR__"westroad2",
	]));
	set("objects",([
		"/d/mingjiao/npc/miaozuwushi":4,	
	]));
	set("coor/x", -31000);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}