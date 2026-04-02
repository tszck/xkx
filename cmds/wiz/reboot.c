// shutdown.c
inherit F_CLEAN_UP;

#include <net/daemons.h>



int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);

	message( "system", "遊戲重新啓動，請稍候一分鐘再 login 。\n", users() );

	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

	shutdown(0);
	return 1;
}
int help (object me)
{
        write(@HELP
指令格式: shutdown
 
馬上重新起動遊戲。
 
HELP
);
        return 1;
}
 
