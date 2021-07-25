//
// Created by Spud on 7/22/21.
//

#include "catch2/catch.hpp"
#include "npf/content/formatting.hpp"
#include "themeTest.hpp"
#include "blogTest.hpp"

TEST_CASE("Blank Formatting Test", "[Formatting]") {

	Formatting formatting;

	REQUIRE(formatting.type.empty());
	REQUIRE(formatting.start == 0);
	REQUIRE(formatting.end == 0);
	REQUIRE(formatting.url.empty());

	// Blog
	BlogTest::testBlog(formatting.blog, false, false, "", false, false, false, "", false, "", 0, 0, false,
	                   false, "", 0, 0, "", "", "", "", false, false);

	REQUIRE(formatting.blog.avatar.empty());

	// Blog Theme
	ThemeTest::testTheme(formatting.blog.theme, "", "", "", "",
	                     "", "", "", false, "",
	                     false, false, false, false, "", "", "");

	REQUIRE(formatting.hex.empty());
}

TEST_CASE("Parsing Formatting Test", "[Formatting]") {

	/*
	{
		"type": "text",
		"text": "supercalifragilisticexpialidocious",
		"formatting": [
			{
				"start": 0,
				"end": 20,
				"type": "bold"
			},
			{
				"start": 9,
				"end": 34,
				"type": "italic"
			}
		]
	}
	 */

	/*
	{
		"type": "text",
		"text": "some bold and italic text",
		"formatting": [
			{
				"start": 5,
				"end": 9,
				"type": "bold"
			},
			{
				"start": 14,
				"end": 20,
				"type": "italic"
			}
		]
	}
	 */

	/*
	{
		"type": "text",
		"text": "some small text",
		"formatting": [
			{
				"start": 5,
				"end": 10,
				"type": "small"
			}
		]
	}
	 */

	/*
	{
		"type": "text",
		"text": "Found this link for you",
		"formatting": [
			{
				"start": 6,
				"end": 10,
				"type": "link",
				"url": "https://www.nasa.gov"
			}
		]
	}
	 */

	/*
	{
		"type": "text",
		"text": "Shout out to @david",
		"formatting": [
			{
				"start": 13,
				"end": 19,
				"type": "mention",
				"blog": {
					"uuid": "t:123456abcdf",
					"name": "david",
					"url": "https://davidslog.com/",
				}
			}
		]
	}
	 */

	/*
	{
		"type": "text",
		"text": "Celebrate Pride Month",
		"formatting": [
			{
				"start": 10,
				"end": 15,
				"type": "color",
				"hex": "#ff492f"
			}
		]
	}
	 */

	// Create document parsers for all the json values.
	rapidjson::Document boldItalicDocument, boldItalicDocument2, smallDocument, linkDocument, mentionDocument, colorDocument;

	// Parse the strings into their respective document.
	boldItalicDocument.Parse(
			R"({"type": "text","text": "supercalifragilisticexpialidocious","formatting": [{"start": 0,"end": 20,"type": "bold"},{"start": 9,"end": 34,"type": "italic"}]})");
	boldItalicDocument2.Parse(
			R"({"type": "text","text": "some bold and italic text","formatting": [{"start": 5,"end": 9,"type": "bold"},{"start": 14,"end": 20,"type": "italic"}]})");
	smallDocument.Parse(
			R"({"type": "text","text": "some small text","formatting": [{"start": 5,"end": 10,"type": "small"}]})");
	linkDocument.Parse(
			R"({"type": "text","text": "Found this link for you","formatting": [{"start": 6,"end": 10,"type": "link","url": "https://www.nasa.gov"}]})");
	mentionDocument.Parse(
			R"({"type": "text","text": "Shout out to @david","formatting": [{"start": 13,"end": 19,"type": "mention","blog": {"uuid": "t:123456abcdf","name": "david","url": "https://davidslog.com/"}}]})");
	colorDocument.Parse(
			R"({"type": "text","text": "Celebrate Pride Month","formatting": [{"start": 10,"end": 15,"type": "color","hex": "#ff492f"}]})");

	// Check that the documents are objects and have the member "formatting".
	for (rapidjson::Document *d : std::vector<rapidjson::Document *>(
			{&boldItalicDocument, &boldItalicDocument2, &smallDocument, &linkDocument, &mentionDocument,
			 &colorDocument})) {
		REQUIRE(d->IsObject());
		REQUIRE(d->HasMember("formatting"));
	}

	// Get the formatting from the documents.
	JSON_ARRAY boldItalicArray = boldItalicDocument["formatting"].GetArray();
	JSON_ARRAY boldItalicArray2 = boldItalicDocument2["formatting"].GetArray();
	JSON_ARRAY smallArray = smallDocument["formatting"].GetArray();
	JSON_ARRAY linkArray = linkDocument["formatting"].GetArray();
	JSON_ARRAY mentionArray = mentionDocument["formatting"].GetArray();
	JSON_ARRAY colorArray = colorDocument["formatting"].GetArray();

	// Get the objects from the array.
	JSON_OBJECT boldItalicObject_0 = boldItalicArray[0].GetObj();
	JSON_OBJECT boldItalicObject_1 = boldItalicArray[1].GetObj();
	JSON_OBJECT boldItalicObject2_0 = boldItalicArray2[0].GetObj();
	JSON_OBJECT boldItalicObject2_1 = boldItalicArray2[1].GetObj();
	JSON_OBJECT smallObject = smallArray[0].GetObj();
	JSON_OBJECT linkObject = linkArray[0].GetObj();
	JSON_OBJECT mentionObject = mentionArray[0].GetObj();
	JSON_OBJECT colorObject = colorArray[0].GetObj();

	// Create the formatting objects.
	Formatting boldItalicFormatting_0, boldItalicFormatting_1, boldItalicFormatting2_0, boldItalicFormatting2_1,
			smallFormatting, linkFormatting, mentionFormatting, colorFormatting;

	// Populate the formatting objects.
	boldItalicFormatting_0.populateNPF(boldItalicObject_0);
	boldItalicFormatting_1.populateNPF(boldItalicObject_1);
	boldItalicFormatting2_0.populateNPF(boldItalicObject2_0);
	boldItalicFormatting2_1.populateNPF(boldItalicObject2_1);
	smallFormatting.populateNPF(smallObject);
	linkFormatting.populateNPF(linkObject);
	mentionFormatting.populateNPF(mentionObject);
	colorFormatting.populateNPF(colorObject);

	// TODO Actual tests

}
