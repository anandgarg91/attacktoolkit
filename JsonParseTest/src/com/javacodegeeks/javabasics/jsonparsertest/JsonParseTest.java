package com.javacodegeeks.javabasics.jsonparsertest;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.io.*;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;
import java.net.*;
public class JsonParseTest {

	private static final String filePath = "/home/anand/Desktop/project/new_parse_Aliazzzz_Applied-Design-Patterns-in-CODESYS-V3.json";
	
	public static void main(String[] args) {

		try {
			// read the json file
			FileReader reader = new FileReader(filePath);

			JSONParser jsonParser = new JSONParser();
			JSONObject jsonObject = (JSONObject) jsonParser.parse(reader);

			// get a String from the JSON object
			long count =  (long) jsonObject.get("total_count");
			System.out.println("Count of Project: " + count);

			// get a number from the JSON object
			//long id =  (long) jsonObject.get("id");
			//System.out.println("The id is: " + id);

			// get an array from the JSON object
			JSONArray item= (JSONArray) jsonObject.get("items");
			
			// take the elements of the json array
			for(int i=0; i<item.size(); i++){
				//System.out.println("The " + i + " element of the array: "+item.get(i));
			}
			Iterator i = item.iterator();

			// take each value from the json array separately
			int counter=0;
			while (i.hasNext()) {
				JSONObject innerObj = (JSONObject) i.next();
				String fileSeparator = System.getProperty("file.seperator");
				
				String absoluteFilePath = fileSeparator + "home" + fileSeparator + "anand" + fileSeparator + "project" + counter + ".project";
				String url = (String) innerObj.get("html_url");
				BufferedInputStream inputStream = new BufferedInputStream(new URL(url).openStream());
				FileOutputStream fileOS = new FileOutputStream("/home/anand/Desktop/project1/project"+counter+".project");
				byte data[] = new byte[1024];
				int byteContent;
				while ((byteContent = inputStream.read(data, 0, 1024)) != -1) {
					fileOS.write(data, 0, byteContent);
				}
				System.out.println("Project---->"+ innerObj.get("name")
				+ 	" with url-----> " + innerObj.get("html_url"));
				counter++;
			}
			// handle a structure into the json object
			//JSONObject structure = (JSONObject) jsonObject.get("job");
			//System.out.println("Into job structure, name: " + structure.get("name"));
			
		} catch (FileNotFoundException ex) {
			ex.printStackTrace();
		} catch (IOException ex) {
			ex.printStackTrace();
		} catch (ParseException ex) {
			ex.printStackTrace();
		} catch (NullPointerException ex) {
			ex.printStackTrace();
		}

	}

}
