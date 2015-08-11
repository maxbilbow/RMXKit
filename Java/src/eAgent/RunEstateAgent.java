package eAgent;

import javax.swing.JFrame;

import eAgent.control.MainPanelControl;

public class RunEstateAgent extends EZ {
	/**
	 * @param args <br>
	 * Runs the package
	 */
	public static void main (String[] args){
		JFrame F = new JFrame();
	    MainPanelControl P;
		try {
			P = new MainPanelControl();
		    F.add(P);
		    F.setVisible(true);
		    F.pack();
		    F.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			print("main error: ");
			println(e);
		}

	}
}
