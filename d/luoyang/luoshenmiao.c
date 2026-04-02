// Room: /d/luoyang/luoshenmiao.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "洛神廟");
	set("long",  @LONG
在神話傳說中，江河湖泊都是有神類居住管理的，譬如四海中的龍
王兄弟們。據說，掌管洛河水印的“洛神”是位仙女，以前，人們都認
爲她是伏羲氏的女兒宓妃。進得廟來，面對洛神塑像，恐怕馬上湧上心
頭的便是曹子建得文字吧。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"northeast" : __DIR__"southroad",
	]));
	set("no_clean_up", 0);
	set("coor/x", -600);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
