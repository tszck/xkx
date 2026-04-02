// /d/changan/beilin.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "碑林");
	set  ("long",  @LONG
這裏便是天下聞名的長安碑林。相傳建於北宋元佑年間。碑林裏碑
石墓誌林立，自漢至清，薈萃各代名家手筆。真草隸篆，琳琅滿目。更
有昭陵六駿浮雕石刻，直看得你眼花繚亂。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north"     :  __DIR__"westroad1",
		"east"      :  __DIR__"zaoxiang",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5060);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
