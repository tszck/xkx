//room: neitang.c
inherit ROOM;

void create()
{
	set("short","內堂");
	set("long",@LONG
這是一間雅緻的內堂，佈置簡單而典雅。裏面站着個一身淡綠的女
郎，向着你似笑非笑。似乎是江南靈秀造了這樣一個小美人。
LONG );
	set("exits",([
		"north" : __DIR__"qinyun",
	]));
	set("objects",([
		CLASS_D("murong")+"/abi" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1510);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}