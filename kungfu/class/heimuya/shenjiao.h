// shenjiao.h 入教
int do_join(object ob, object obj)
{
	object me;
	string pname ;
	mapping party;
	string *partyname = ({ HIG"青龍", HIW"白虎", HIC"風雷" });

	me = this_object () ;
	ob = this_player () ;

	if(ob->query("party") && ob->query("party/party_name")==HIB"日月神教"NOR)
	{
		message_vision("$N搖搖頭，對$n說道：你已經是我神教的人了。\n",me,ob);
		return 1;
	}
	if(ob->query("party") && ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		message_vision("$N搖搖頭，對$n說道：你已經加入其他幫會了，不能再入我日月神教。\n",me,ob);
		return 1;
	}
   	if( !mapp(party = ob->query("party")) )
   	{
		if ( (string)ob->query("gender") == "女性" ) pname=HIM"天香";
		else pname=partyname[random(sizeof(partyname))];
		if ( (string)ob->query("gender") == "女性" )
			command("say 我神教又得一女中豪傑，真是可喜可賀 !");
		else 
			command("say 我神教又得一英雄好漢，真是可喜可賀 !");

		party = allocate_mapping(5);
		party["party_name"] = HIB "日月神教" NOR;
		party["rank"] = pname+"堂教衆"NOR;
		party["level"] = 1;
		party["tasks"] = 0;
		party["enter_time"] = time();
		ob->set("party", party);

		command("smile");
		message_vision("$N對$n說道：我渡你入教，你暫時先編入神教"+pname+"堂！\n", me, ob);
		return 1;
	}
        command("?");
        command("say 這東西給我可沒有什麼用。");
	return 0;

}

