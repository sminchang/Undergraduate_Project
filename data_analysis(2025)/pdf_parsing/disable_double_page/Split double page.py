import os
from PyPDF2 import PdfReader, PdfWriter # pip install PyPDF2
import copy

def unsplit_collected_pages(input_pdf_path, output_dir_path):
    """
    PDF의 모든 페이지에 대해 2페이지 모아찍기를 해제하여 새로운 PDF 파일을 지정된 디렉터리에 저장합니다.
    출력 파일명은 '원본 파일명_모아찍기해제.pdf' 형식으로 자동 생성됩니다.

    Args:
        input_pdf_path (str): 원본 PDF 파일 경로
        output_dir_path (str): 결과 파일을 저장할 디렉터리 경로
    """
    try:
        if not os.path.exists(output_dir_path):
            os.makedirs(output_dir_path)

        # 출력 파일 경로 생성
        base_filename = os.path.basename(input_pdf_path)
        filename_without_ext, ext = os.path.splitext(base_filename)
        output_filename = f"{filename_without_ext}_모아찍기해제{ext}"
        output_pdf_path = os.path.join(output_dir_path, output_filename)

        pdf_reader = PdfReader(input_pdf_path)
        output_pdf_writer = PdfWriter()
        total_pages = len(pdf_reader.pages)

        for page_num in range(total_pages):
            page = pdf_reader.pages[page_num]

            # deepcopy를 사용하여 원본 페이지 객체를 안전하게 복사
            left_page = copy.deepcopy(page)
            right_page = copy.deepcopy(page)

            # 원본 페이지의 너비와 높이 정보 가져오기
            page_width = page.mediabox.width
            page_height = page.mediabox.height

            # 왼쪽 절반을 새로운 페이지로 설정
            left_page.mediabox.upper_right = (page_width / 2, page_height)
            left_page.cropbox.upper_right = (page_width / 2, page_height)
            output_pdf_writer.add_page(left_page)

            # 오른쪽 절반을 새로운 페이지로 설정
            right_page.mediabox.lower_left = (page_width / 2, 0)
            right_page.cropbox.lower_left = (page_width / 2, 0)
            output_pdf_writer.add_page(right_page)
            
        # 분할된 페이지들을 새로운 PDF 파일로 저장
        with open(output_pdf_path, "wb") as f:
            output_pdf_writer.write(f)
        
        print(f"\n모아찍기 해제가 완료되었습니다. 저장된 파일: {output_pdf_path}")

    except FileNotFoundError:
        print(f"오류: 파일을 찾을 수 없습니다. 경로를 확인하세요: {input_pdf_path}")
    except Exception as e:
        print(f"오류가 발생했습니다: {e}")

if __name__ == "__main__":
    input_pdf = r"C:\Users\yunis\경기도_지방재정\2025 본예산안 사업설명서.pdf"
    output_dir = r"C:\Users\yunis\desktop\test"
    
    unsplit_collected_pages(input_pdf, output_dir)
